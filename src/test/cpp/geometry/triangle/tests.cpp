#include "src/test/cpp/geometry/triangle/fixture.h"

TEST_F(TriangleTest, ShouldTranslateTrianglePositiveFromZeroOrigin)
{
  this->triangle = {
    {0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}};

  this->triangle.translate({3,3});

  Geometry::Triangle correctTriangle {{
    {3,3}, {4,4}, {5,3}
  }};

  this->compare(correctTriangle, this->triangle);
}

TEST_F(TriangleTest, ShouldTranslateTriangleNegativeFromZeroOrigin)
{

  this->triangle = {{
    {0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}}};

  this->triangle.translate({-3,-3});

  Geometry::Triangle correctTriangle = {{
    {-3,-3}, {-2,-2}, {-1,-3}
  }};

  this->compare(correctTriangle, this->triangle);
}

TEST_F(TriangleTest, ShouldTranslateTriangleFromNonZero)
{
  this->triangle = {{
    {5, 5}, {10, 15}, {15, 7}
  }};
  
  this->triangle.translate({3,3});

  Geometry::Triangle correctTriangle = {{
    {8,8}, {13,18}, {18,10}
  }};

  this->compare(correctTriangle, this->triangle);
}

TEST_F(TriangleTest, ShouldTranslateTriangleNegativeFromNonZero)
{
  this->triangle = {{
    {5, 5}, {10, 15}, {15, 7}
  }};

  this->triangle.translate({-3,-3});

  Geometry::Triangle correctTriangle = {{
    {2,2}, {7,12}, {12,4}
  }};

  this->compare(correctTriangle, this->triangle);
}

TEST_F(TriangleTest, ShouldScaleTriangle)
{
  this->triangle = {{
    {0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}
  }};

  this->triangle.scale(4);

  Geometry::Triangle correctTriangle = {{
    {0.0, 0.0}, {4, 4}, {8, 0.0}
  }};

  this->compare(correctTriangle, this->triangle);
}

TEST_F(TriangleTest, ShouldScaleTriangleFromNonZeroOrigin)
{
  this->triangle = {{
    {5, 5}, {10, 15}, {15, 7}}};

  this->triangle.scale(2);

  Geometry::Triangle correctTriangle = {{
    {5, 5}, {15, 25}, {25, 9}
  }};

  this->compare(correctTriangle, this->triangle);
}

TEST_F(TriangleTest, ShouldIndexTriangleWithVerticeSubscriptOperator)
{
  this->triangle = {{
    {0.0, 0.0}, {3, 6}, {6, 0.0}}};

  auto y2 = triangle["y2"];
  auto x3 = triangle["x3"];

  double correctY1 = 6;
  double correctX2 = 6;

  EXPECT_DOUBLE_EQ(correctY1, y2);
  EXPECT_DOUBLE_EQ(correctX2, x3);
}

TEST_F(TriangleTest, ShouldGetMiddleVertexOfTriangle)
{
  this->triangle = {{
    {0.0, 0.0}, {3, 6}, {6, 0.0}}};

  auto point = triangle.middleVertex();
  Maths::Vector correctPoint = {3, 6};

  this->compare(correctPoint, point);
}

TEST_F(TriangleTest, ShouldGetMiddleInterceptPointOfTriangle)
{
  this->triangle = {{
    {0.0, 0.0}, {3, 6}, {6, 0.0}}};

  auto point = triangle.interceptOfMiddleVertex();
  Maths::Vector correctPoint = {3, 0};

  this->compare(correctPoint, point);
}

TEST_F(TriangleTest, ShouldSplitTriangle)
{
  this->triangle = {{
    {0.0, 0.0}, {3, 6}, {6, 0.0}}};

  auto triangles = this->triangle.split();

  auto triangle1 = triangles.first;
  Geometry::Triangle correctTriangle1 {{{0.0, 0.0}, {3, 6}, {3, 0.0}}};

  this->compare(correctTriangle1, triangle1);

  auto triangle2 = triangles.second;
  Geometry::Triangle correctTriangle2 {{{3, 0.0}, {3, 6}, {6, 0.0}}};

  this->compare(correctTriangle2, triangle2);
}

TEST_F(TriangleTest, ShouldDetermineTriangleNeedsSplitting)
{
  this->triangle = {{
    {0.0, 0.0}, {3, 6}, {6, 0.0}}};

  EXPECT_TRUE(this->triangle.shouldSplit());
}

TEST_F(TriangleTest, ShouldDetermineTriangleDoesNotNeedSplitting)
{
  this->triangle = {{
    {0.0, 0.0}, {3, 0.0}, {3, 3}}};

  EXPECT_FALSE(this->triangle.shouldSplit());
}