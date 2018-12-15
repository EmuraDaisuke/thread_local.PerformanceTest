# thread_local.PerformanceTest
thread_local変数(class)アクセスのパフォーマンステスト

## Windows10
||Direct|Reference|
|-|:-:|:-:|
|Microsoft(R) C/C++ Version 19.16.27025.1 for x64|0.088201|0.065236|
|gcc version 8.2.0 (Rev3, Built by MSYS2 project)|0.833613|0.094968|

## debian
||Direct|Reference|
|-|:-:|:-:|
|clang version 3.8.1-24 (tags/RELEASE_381/final)|0.0900844|0.0486281|
|gcc version 6.3.0 20170516 (Debian 6.3.0-18+deb9u1)|0.0968881|0.0491672|
