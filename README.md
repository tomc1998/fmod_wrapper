# Building

* Insert all fmod studio APIs into lib/
    This includes ALL files found under lib/ directories in the fmod studio API download (latest version 1, not version 2), try `find <FMOD API Download>/api/ -iname lib`
* Insert all fmod studio headers into include/
    This includes ALL files found under inc/ directories in the fmod studio API download (latest version 1, not version 2), try `find <FMOD API Download>/api/ -iname inc`

Then:

```
mkdir build
cd build
cmake ..
make
```
