# libcurl examples

## Installing libcurl

```
sudo apt install libcurl4-openssl-dev
```

## Installing [nlohmann/json](https://github.com/nlohmann/json)

- clone source code
- create build directory `mkdir build`
- go to build folder     `cd build`
- turn off unit tests    `cmake .. -DJSON_BuildTests=Off`
- build                  `cmake --build .`
- install                `sudo make install`

## Building and running code

```sh
# build
g++ xxx.cpp -lcurl

# run
./a.out
```