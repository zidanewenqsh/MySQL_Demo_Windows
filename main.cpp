#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <iostream>
#include <memory>

int main() {
	try {
		// 初始化 MySQL 驱动
		sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
		// 检查驱动实例是否为 nullptr
		if (driver == nullptr) {
			std::cerr << "Failed to get MySQL driver instance." << std::endl;
			return 1; // 退出程序，驱动加载失败
		}
		// 创建连接
		std::unique_ptr<sql::Connection> conn(driver->connect("tcp://127.0.0.1:3306", "root", "root"));

		// 检查连接是否成功
		if (conn == nullptr) {
			std::cerr << "Failed to establish connection to the database." << std::endl;
			return 1; // 退出程序，连接失败
		}


		// 选择数据库
		conn->setSchema("test_db");

		// 创建 Statement 对象
		std::unique_ptr<sql::Statement> stmt(conn->createStatement());

		// 执行查询
		stmt->executeUpdate("CREATE TABLE IF NOT EXISTS example_table (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255))");
		stmt->executeUpdate("INSERT INTO example_table (name) VALUES ('Alice'), ('Bob')");

		// 执行查询并获取结果
		std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM example_table"));

		// 输出查询结果
		while (res->next()) {
			std::cout << "ID: " << res->getInt("id") << ", Name: " << res->getString("name") << std::endl;
		}
	}
	catch (sql::SQLException &e) {
		std::cerr << "SQLException: " << e.what() << std::endl;
		std::cerr << "SQLState: " << e.getSQLState() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
