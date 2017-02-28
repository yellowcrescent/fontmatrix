
# FontMatrix

![](https://ss.ycnrg.org/jotunn_20170227_215749.png)

This fork of FontMatrix fixes build issues related to new versions of libICU, which allows the package to build and link correctly. The original project and website seem to no longer be maintained.

## Building on Ubuntu 16.04

Abbreviated build instructions for Ubuntu 16.04 (and likely Debian 8). For older versions of Ubuntu, the latest version of FontMatrix is included in the universe repository, so it's best to install from there. For full build instructions, check out debian-ubuntu-install.txt or INSTALL in the project root.

 sudo apt-get install libqt4-dev libqtwebkit-dev libqt4-sql-sqlite python-dev libicu-dev libharfbuzz-dev
 git clone https://github.com/yellowcrescent/fontmatrix.git
 cd fontmatrix
 mkdir build && cd build
 cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DWANT_HARFBUZZ:bool=true -DWANT_ICU:bool=true
 make -j8
 sudo make install


-------------------------------------------------------------------------

Fontmatrix is a font management application for Linux, Mac and Windows, 
concieved by Pierre Marchand in 2007.

It helps keeping your font collection in order, allowing you to enable and disable availability of fonts and font families in your system. This is a quite helpful tool for designers who tend to have huge collections of typefaces.

Searching for the right font in Fontmatrix is easy thanks to advanced support 
for Panose and user defined filters, as well as tags.

Fontmatrix is also useful for type designers and enthusiasts, because it 
simplifies testing of OpenType features and allows comparing fonts glyph by 
glyph which is extremely useful for learning type design.

There is an extremely low-traffic mailing list available:

https://mail.gna.org/listinfo/undertype-users/
