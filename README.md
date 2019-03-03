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
`Where is the source code:` には `C:\Users\hoge\sample\` を指定する.
`Where to build the binaries:` には `C:\Users\hoge\sample\build\` を指定する.
`cmake` が `boost` の検索に失敗することがあるので, `Add Entry` で

- `Name`: `BOOST_ROOT`
- `Type`: `PATH`
- `Value`: `boost` の `include`, `lib` をディレクトリを含むディレクトリ.

のように指定する. あとは, `Configure` -> `Generate` -> `Open Project` として,
Visual Studio でビルドすればよい. ビルドの生成物は以下の通り.

- `build/bin/main.exe` (Release)
- `build/lib/sample.lib` (Release)
- `build/bin/main-debug.exe` (Debug)
- `build/lib/sample-debug.lib` (Release)

### Linux

`apt install cmake` などをする.

このリポジトリを `/home/hoge/sample/` にクローンしてあるとする.

```bash
cd /home/hoge/sample/
mkdir build && cd build
cmake ..
make
```

ビルドの生成物は以下の通り.

- `build/bin/main`
- `build/lib/libsample.a`
