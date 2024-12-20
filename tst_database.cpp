#include <gtest/gtest.h>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include "database.h"

class DatabaseTest : public ::testing::Test {
protected:
    void SetUp() override {
        db.initialize();
    }

    database db;
};

TEST_F(DatabaseTest, LoadDataReturnsCorrectData) {
    // Act
    QSqlQuery query = db.loadData("SELECT * FROM employee");

    // Assert
    ASSERT_TRUE(query.next());  // Ensure there is at least one row
    QSqlRecord record = query.record();

    EXPECT_EQ(record.value("username").toString(), "admin");
    EXPECT_EQ(record.value("password").toString(), "");
}

TEST_F(DatabaseTest, LoadDataHandlesEmptyQuery) {
    // Act
    QSqlQuery query = db.loadData("SELECT * FROM employee WHERE username = 'nonexistent'");

    // Assert
    EXPECT_FALSE(query.next());  // No rows should be returned
}
