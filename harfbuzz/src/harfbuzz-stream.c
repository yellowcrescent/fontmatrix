/*******************************************************************
 *
 *  Copyright 2005  David Turner, The FreeType Project (www.freetype.org)
 *  Copyright 2007  Trolltech ASA
 *  Copyright 2007  Red Hat, Inc
 *
 *  This is part of HarfBuzz, an OpenType Layout engine library.
 *
 *  See the file name COPYING for licensing information.
 *
 ******************************************************************/
#include "harfbuzz-impl.h"
#include "harfbuzz-stream-private.h"
#include <stdlib.h>

#if 0
#include <stdio.h>
#define  LOG(x)  _hb_log x

static void
_hb_log( const char*   format, ... )
{
  va_list  ap;
 
  va_start( ap, format );
  vfprintf( stderr, format, ap );
  va_end( ap );
}

#else
#define  LOG(x)  do {} while (0)
#endif

HB_INTERNAL void
_hb_close_stream( HB_Stream stream )
{
  if (!stream)
      return;
  free(stream->base);
  free(stream);
}


HB_INTERNAL HB_Int
_hb_stream_pos( HB_Stream stream )
{
  LOG(( "_hb_stream_pos() -> %ld\n", stream->pos ));
  return stream->pos;
}


HB_INTERNAL HB_Error
_hb_stream_seek( HB_Stream stream,
		 HB_UInt pos )
{
  HB_Error  error = 0;

  stream->pos = pos;
  if (pos > stream->size)
      error = ERR(HB_Err_Read_Error);

  LOG(( "_hb_stream_seek(%ld) -> 0x%04X\n", pos, error ));
  return error;
}


HB_INTERNAL HB_Error
_hb_stream_frame_enter( HB_Stream stream,
			HB_UInt count )
{
  HB_Error  error = HB_Err_Ok;

  /* check new position, watch for overflow */
  if (HB_UNLIKELY (stream->pos + count > stream->size ||
		   stream->pos + count < stream->pos))
  {
    error = ERR(HB_Err_Read_Error);
    goto Exit;
  }

  /* set cursor */
  stream->cursor = stream->base + stream->pos;
  stream->pos   += count;

Exit:
  LOG(( "_hb_stream_frame_enter(%ld) -> 0x%04X\n", count, error ));
  return error;
}


HB_INTERNAL void
_hb_stream_frame_exit( HB_Stream stream )
{
  stream->cursor = NULL;

  LOG(( "_hb_stream_frame_exit()\n" ));
}