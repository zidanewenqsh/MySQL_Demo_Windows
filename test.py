import pymysql

def main():
    try:
        # 连接到 MySQL 数据库
        conn = pymysql.connect(
            host="127.0.0.1",    # MySQL 服务器的地址
            user="root",         # MySQL 用户名
            password="root",     # MySQL 密码
            database="test_db",  # 使用的数据库
            port=3306            # 端口号（默认为3306）
        )

        # 创建一个 Cursor 对象，用于执行 SQL 查询
        cursor = conn.cursor()

        # 创建表格（如果不存在）
        cursor.execute("""
            CREATE TABLE IF NOT EXISTS example_table (
                id INT AUTO_INCREMENT PRIMARY KEY,
                name VARCHAR(255) NOT NULL
            )
        """)

        # 插入数据
        cursor.execute("INSERT INTO example_table (name) VALUES ('Alice'), ('Bob')")
        conn.commit()  # 提交事务，确保数据保存到数据库

        # 查询数据
        cursor.execute("SELECT * FROM example_table")

        # 输出查询结果
        for row in cursor.fetchall():  # 获取所有结果
            print(f"ID: {row[0]}, Name: {row[1]}")

        # 关闭 cursor 和连接
        cursor.close()
        conn.close()

    except pymysql.MySQLError as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
