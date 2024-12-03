#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    unsigned int id;
    char *name;

    // 初始化 MySQL 连接
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // 连接到数据库
    if (mysql_real_connect(conn, "127.0.0.1", "root", "root", "test_db", 3306, NULL, 0) == NULL) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    // 创建表
    if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS example_table (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255))")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
    } else {
        if ((result = mysql_store_result(conn)) != NULL) {
            // 处理存储结果（如果有）
            mysql_free_result(result);
        }
    }

    // 插入数据
    if (mysql_query(conn, "INSERT INTO example_table (name) VALUES ('Alice'), ('Bob')")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
    } else {
        if ((result = mysql_store_result(conn)) != NULL) {
            // 处理存储结果（如果有）
            mysql_free_result(result);
        }
    }

    // 查询数据
    if (mysql_query(conn, "SELECT * FROM example_table")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
    } else {
        result = mysql_store_result(conn);

        // 输出查询结果
        while ((row = mysql_fetch_row(result))) {
            id = atoi(row[0]);
            name = row[1];
            printf("ID: %u, Name: %s\n", id, name);
        }

        // 释放结果集
        mysql_free_result(result);
    }

    // 关闭连接
    mysql_close(conn);

    return 0;
}