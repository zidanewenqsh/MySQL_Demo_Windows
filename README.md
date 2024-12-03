# MySQL_Demo_Windows
在windows下c++使用MySQL的案例

## 项目描述
该项目展示了如何在Windows环境下使用C++连接和操作MySQL数据库。通过该案例，您可以学习到如何配置开发环境、编写C++代码与MySQL进行交互。

## 安装和使用步骤

### 1. 安装MySQL数据库
1. **下载并安装MySQL Community Server**
   - 访问 [MySQL下载页面](https://dev.mysql.com/downloads/installer/)，下载适合你系统的 MySQL Community Server。
   - 安装过程中，可以选择配置 `MySQL Server` 和 `MySQL Workbench` 作为管理工具。
   
2. **配置MySQL服务器并创建一个测试数据库**
   - 启动 MySQL Server，使用命令行或 MySQL Workbench 连接到 MySQL 数据库。
   - 创建一个测试数据库，例如：
     ```sql
     CREATE DATABASE test_db;
     USE test_db;
     ```
   - 可以使用此数据库进行开发和测试。

### 2. 安装MySQL Connector/C++
1. **下载并安装MySQL Connector/C++**
   - 访问 [MySQL Connector/C++下载页面](https://dev.mysql.com/downloads/connector/cpp/)，下载适用于 Windows 的 MySQL Connector/C++。
   - 推荐使用版本 8.0.x（与 Visual Studio 2015 兼容）。
   
2. **配置MySQL Connector/C++**
   - 安装完成后，记下 Connector/C++ 的安装路径。
   - 配置环境变量：
     - 在 `系统环境变量` 中，添加 MySQL Connector/C++ 的 `bin` 目录到 `PATH` 环境变量中（例如 `C:\Program Files\MySQL\MySQL Connector C++ 8.0.14\bin`）。

3. **确保与 Visual Studio 2015 兼容**
   - 对于 Visual Studio 2015 用户，请确保使用 MySQL Connector/C++ 8.0.x 版本，这与 Visual Studio 2015 兼容。
   - 如果下载了 Debug 版本，也可以正常使用，只需要在项目中进行调试配置即可。

### 3. 配置开发环境
1. **创建 C++ 项目**
   - 使用 Visual Studio 或其他 C++ 开发工具创建一个新的 C++ 项目。
   - 如果使用 Visual Studio，确保选择 `Visual Studio 2015` 编译器。
   
2. **配置项目以链接 MySQL Connector/C++**
   - 将 `MySQL Connector/C++` 的头文件目录（例如 `C:\Program Files\MySQL\MySQL Connector C++ 8.0.14\include`）添加到项目的 `Include Directories` 中。
   - 将 `MySQL Connector/C++` 的库文件目录（例如 `C:\Program Files\MySQL\MySQL Connector C++ 8.0.14\lib`）添加到项目的 `Library Directories` 中。
   - 在项目的 `Additional Dependencies` 中添加 `mysqlcppconn.lib`。

3. **将依赖的动态链接库复制到构建文件夹**
   - 将以下动态链接库复制到构建文件夹中：
     - `libcrypto-1_1-x64.dll`
     - `libssl-1_1-x64.dll`
     - `mysqlcppconn-9-vs14.dll`
   - 这些文件通常位于 `MySQL Connector/C++` 的 `bin` 目录中。

### 4. 编译和运行
1. **生成工程文件**
   - 使用 Visual Studio 或命令行工具（如 CMake）生成解决方案文件。确保选择合适的编译器（Visual Studio 2015 编译器）。
   
2. **在 Visual Studio 中打开和配置项目**
   - 打开生成的 `.sln` 文件，进入 Visual Studio。
   - 禁用 `ALL_BUILD` 和 `ZERO_CHECK` 项目，确保项目依赖正确。

3. **编译项目**
   - 在 Visual Studio 中编译解决方案，确保没有错误。
   
4. **运行程序**
   - 在 Visual Studio 中运行程序，程序将连接到 MySQL 数据库并执行相应操作。

## 项目结构
MySQL_Demo_Windows/
│
├── build/ # 编译输出目录
│
├── .gitignore # Git忽略文件配置
│
├── CMakeLists.txt # CMake 配置文件 (如果使用 CMake 构建)
│
├── LICENSE # 许可证文件
│
├── main.cpp # 主程序入口
│
├── README.md # 项目的说明文档
│
└── test.py # Python 测试脚本

## 常见问题
- MySQL Connector/C++ 连接失败
  - 确保你安装了适用于你 Visual Studio 版本的 MySQL Connector/C++。
  - 如果出现 std::bad_alloc 错误，通常是由于内存分配失败，检查驱动是否正确加载，或者是否存在其他内存问题。通常与MySQL Connector/C++版本与Visual Studio版本不匹配有关。

- 找不到 mysqlcppconn-9-vs14.dll 文件
  - 确保将 mysqlcppconn-9-vs14.dll 复制到应用程序的工作目录或系统路径中。

- 其他常见错误
  - 确保所有的库和依赖项都已经正确配置和拷贝。