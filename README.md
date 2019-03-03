# cuda-sample

Windows (Visual Studio) と Linux の両方でビルド可能な CUDA プロジェクトを作成する
`CMakeLists.txt` のテンプレート (`boost` 依存のプロジェクトを想定).

- `sample/`: CUDA で書かれた static library. 通常の `C++` から利用可能.
  - `cuda_utility.h`: CUDA と Intellisense の相性が良くないので, Visual Studio の Intellisense を騙して開発しやすくする.
- `main/`: 実際に `sample` ライブラリを利用するサンプルプロジェクト.

Windows だと `Release`, `Debug` フォルダなどができてしまうのが嫌だったので少し工夫した.

## ビルド方法

### Windows

`cmake-gui` をインストールする.

このリポジトリを `C:\Users\hoge\sample\` にクローンしてあるとする.

`cmake-gui`を起動して,
`Where is the source code:` には `C:\Users\hoge\sample\` を,
`Where to build the binaries:` には `C:\Users\hoge\sample\build\` を指定する.
変な場所に `boost` をインストールした場合, `cmake` が `boost` の検索に失敗することがある.
その場合はどこを検索すればよいかのヒントが必要で, `Add Entry` で

- `Name`: `BOOST_ROOT`
- `Type`: `PATH`
- `Value`: `boost` の `include`, `lib` ディレクトリを含むディレクトリ.

のように指定する. あくまでヒントなので, 含んでさえいれば適当でよい (あまりに遠すぎると失敗する可能性はあるが).

あとは,

1. `Configure` (generator を聞かれるので `VS 2017`, `x64` を指定する)
2. `Generate`
3. `Open Project`
4. Visual Studio でビルド

とすればよい. ビルドの生成物は以下の通り.

- `build/bin/main.exe` (Release)
- `build/lib/sample.lib` (Release)
- `build/bin/main-debug.exe` (Debug)
- `build/lib/sample-debug.lib` (Release)

### Linux

このリポジトリを `/home/hoge/sample/` にクローンしてあるとする.

```bash
cd /home/hoge/sample/
mkdir build && cd build
cmake ..
make
```

基本的にはこれだけでよい. コンパイラを指定したいとき, `boost` の検索に失敗したときは,
`cmake ..` を `cmake -DCMAKE_CXX_COMPILER=clang++ -DBOOST_ROOT=/path/to/boost ..` などと変更すればよい.

ビルドの生成物は以下の通り.

- `build/bin/main`
- `build/lib/libsample.a`
