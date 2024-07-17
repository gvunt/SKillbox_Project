#include <gtest/gtest.h>
#include "InvertedIndex.h"

TEST(InvertedIndexTest, AddDocument) {
    InvertedIndex index;
    index.addDocument("example document text", 1);

    auto docs = index.getDocuments("example");
    EXPECT_EQ(docs.size(), 1);
    EXPECT_EQ(docs.count(1), 1);

    docs = index.getDocuments("document");
    EXPECT_EQ(docs.size(), 1);
    EXPECT_EQ(docs.count(1), 1);

    docs = index.getDocuments("text");
    EXPECT_EQ(docs.size(), 1);
    EXPECT_EQ(docs.count(1), 1);
}

TEST(InvertedIndexTest, GetDocuments) {
    InvertedIndex index;
    index.addDocument("example document text", 1);
    index.addDocument("another example text", 2);

    auto docs = index.getDocuments("example");
    EXPECT_EQ(docs.size(), 2);
    EXPECT_EQ(docs.count(1), 1);
    EXPECT_EQ(docs.count(2), 1);

    docs = index.getDocuments("another");
    EXPECT_EQ(docs.size(), 1);
    EXPECT_EQ(docs.count(2), 1);
}
