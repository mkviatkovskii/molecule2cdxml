# molecule2cdxml
Simple utility to convert molecules to CDXML format using Indigo toolkit

## Dependencies
* C++ compiler with support for C++14
* CMake of version 3.4 or higher
* Git
* [Indigo](https://github.com/epam/indigo) cheminformatics toolkit

## Instructions:
1. Install system requirements (example for Ubuntu):
    ```bash
    sudo apt update
    sudo apt install -y cmake g++ git make
    ```
2. Clone Indigo repository:
    ```bash
    git clone https://github.com/epam/indigo
    ```
3. Create CMake build folder and prepare build scripts
    ```bash
    mkdir build
    cd build
    cmake ..
    ```
4. Build utility
    ```bash
    cmake --build . --target molecule2cdxml --config Release 
    ```
   On Linux you may add additional parameters to parallelize and speed
   up the compilation:
   ```bash
   cmake --build . --target molecule2cdxml --config Release -- -j $(nproc)
   ```
5. Check that utility works fine:
    ```
    $ ./molecule2cdxml c1ccccc1
    <?xml version="1.0" encoding="UTF-8"?>
    <!DOCTYPE CDXML SYSTEM "http://www.cambridgesoft.com/xml/cdxml.dtd">
    <CDXML BondLength="30.000000" LabelFont="3" CaptionFont="4">
        <fonttable>
            <font id="1" charset="utf-8" name="Arial"/>
            <font id="2" charset="utf-8" name="Times New Roman"/>
        </fonttable>
        <colortable>
            <color r="1" g="1" b="1"/>
            <color r="0" g="0" b="0"/>
            <color r="1" g="0" b="0"/>
            <color r="1" g="1" b="0"/>
            <color r="0" g="1" b="0"/>
            <color r="0" g="1" b="1"/>
            <color r="0" g="0" b="1"/>
            <color r="1" g="0" b="1"/>
            <color r="0.5" g="0.5" b="0.5"/>
        </colortable>
        <page HeightPages="1" WidthPages="1">
            <fragment>
                <n id="1" Element="6">
                    <t p="0.000000 -0.000000" Justification="Center">
                        <s font="3" size="10" face="96">CH4</s>
                    </t>
                </n>
            </fragment>
        </page>
    </CDXML>
    ```
