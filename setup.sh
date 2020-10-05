git clone https://github.com/wxWidgets/wxWidgets.git
cd wxWidgets
mkdir gtk-build
../configure
cd ..
g++ src/main.cxx `wx-config --cxxflags --libs` -o main