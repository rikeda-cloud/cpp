#include "Fixed.hpp"
#include <gtest/gtest.h>

TEST(FixedTest, TestComparisonOperators) {
	float	float1(42.42f);
	float	float2(111.111f);
	float	float3(123.123f);
	Fixed	fixed1(float1);
	Fixed	fixed2(float2);
	Fixed	fixed3(float3);

	// >
	EXPECT_EQ(fixed1 > fixed2, float1 > float2);
	EXPECT_EQ(fixed2 > fixed3, float2 > float3);
	EXPECT_EQ(fixed3 > fixed1, float3 > float1);

	// <
	EXPECT_EQ(fixed1 < fixed2, float1 < float2);
	EXPECT_EQ(fixed2 < fixed3, float2 < float3);
	EXPECT_EQ(fixed3 < fixed1, float3 < float1);

	// >=
	EXPECT_EQ(fixed1 >= fixed2, float1 >= float2);
	EXPECT_EQ(fixed2 >= fixed3, float2 >= float3);
	EXPECT_EQ(fixed3 >= fixed1, float3 >= float1);

	// <=
	EXPECT_EQ(fixed1 <= fixed2, float1 <= float2);
	EXPECT_EQ(fixed2 <= fixed3, float2 <= float3);
	EXPECT_EQ(fixed3 <= fixed1, float3 <= float1);

	// ==
	EXPECT_EQ(fixed1 == fixed2, float1 == float2);
	EXPECT_EQ(fixed2 == fixed3, float2 == float3);
	EXPECT_EQ(fixed3 == fixed1, float3 == float1);
	EXPECT_EQ(fixed1 == fixed1, float1 == float1);

	// !=
	EXPECT_EQ(fixed1 == fixed2, float1 == float2);
	EXPECT_EQ(fixed2 == fixed3, float2 == float3);
	EXPECT_EQ(fixed3 == fixed1, float3 == float1);
	EXPECT_EQ(fixed1 == fixed1, float1 == float1);
}

// 固定小数点の特徴として浮動小数点から変換する際に情報が落ちる
// そのため、EXPECT_NEARのEPSの設定を演算子ごとに変えている
TEST(FixedTest, TestArithmeticOperators) {
	float	float1(111.111f);
	float	float2(42.42f);
	Fixed	fixed1(float1);
	Fixed	fixed2(float2);

	//// +
	EXPECT_NEAR(float1 + float2, (fixed1 + fixed2).toFloat(), 0.001);

	//// -
	// 演算結果が正
	EXPECT_NEAR(float1 - float2, (fixed1 - fixed2).toFloat(), 0.01);
	// 演算結果が負
	EXPECT_NEAR(float2 - float1, (fixed2 - fixed1).toFloat(), 0.01);

	//// *
	EXPECT_NEAR(float1 * float2, (fixed1 * fixed2).toFloat(), 1);

	//// /
	EXPECT_NEAR(float1 / float2, (fixed1 / fixed2).toFloat(), 0.01);
	EXPECT_NEAR(float2 / float1, (fixed2 / fixed1).toFloat(), 0.01);
}

TEST(FixedTest, TestIncrementDecrementOperators) {
	Fixed	fixed1;
	Fixed	fixed2;

	// 前置++演算を 動かしたビット*10 行い、合計で10.0インクリメントする
	fixed1.setRawBits(0);
	for (int i = 0; i < (10 * (1 << 8)); i++)
		++fixed1;
	EXPECT_EQ(fixed1.toFloat(), 10.0f);

	// 後置++演算を 動かしたビット*10 行い、合計で10.0インクリメントする
	fixed1.setRawBits(0);
	for (int i = 0; i < (10 * (1 << 8)); i++)
		fixed1++;
	EXPECT_EQ(fixed1.toFloat(), 10.0f);

	// 前置--演算を 動かしたビット*10 行い、合計で10.0デクリメントする
	fixed1.setRawBits(0);
	for (int i = 0; i < (10 * (1 << 8)); i++)
		--fixed1;
	EXPECT_EQ(fixed1.toFloat(), -10.0f);

	// 後置--演算を 動かしたビット*10 行い、合計で10.0デクリメントする
	fixed1.setRawBits(0);
	for (int i = 0; i < (10 * (1 << 8)); i++)
		fixed1--;
	EXPECT_EQ(fixed1.toFloat(), -10.0f);

	// 前置と後置++演算子で前置++演算子の方が値が早く増える
	fixed1.setRawBits(0);
	fixed2.setRawBits(0);
	EXPECT_LT(fixed1++, ++fixed2);

	// 前置と後置--演算子で前置--演算子の方が値が早く減る
	fixed1.setRawBits(0);
	fixed2.setRawBits(0);
	EXPECT_LT(--fixed1, fixed2--);

	// 後置--演算子と後置++演算子は比較をした後に値の増減が行われる
	fixed1.setRawBits(0);
	fixed2.setRawBits(0);
	EXPECT_EQ(fixed1--, fixed2++);
	EXPECT_NE(fixed1, fixed2);
}

TEST(FixedTest, TestMinMaxFunctions) {
	float		float1(1.1f);
	float		float2(1.11f);
	Fixed		fixed1(float1);
	Fixed		fixed2(float2);
	const Fixed	const_fixed1(float1);
	const Fixed	const_fixed2(float2);

	// min
	EXPECT_EQ(fixed1.toFloat(), Fixed::min(fixed1, fixed2).toFloat());
	EXPECT_EQ(const_fixed1.toFloat(), Fixed::min(const_fixed1, const_fixed2).toFloat());
	EXPECT_EQ(fixed1.toFloat(), Fixed::min(fixed2, fixed1).toFloat());
	EXPECT_EQ(const_fixed1.toFloat(), Fixed::min(const_fixed2, const_fixed1).toFloat());

	// max
	EXPECT_EQ(fixed2.toFloat(), Fixed::max(fixed1, fixed2).toFloat());
	EXPECT_EQ(const_fixed2.toFloat(), Fixed::max(const_fixed1, const_fixed2).toFloat());
	EXPECT_EQ(fixed2.toFloat(), Fixed::max(fixed2, fixed1).toFloat());
	EXPECT_EQ(const_fixed2.toFloat(), Fixed::max(const_fixed2, const_fixed1).toFloat());

	// 値が0の場合のmin, max
	fixed1.setRawBits(0);
	fixed2.setRawBits(0);
	EXPECT_EQ(fixed1.toFloat(), Fixed::min(fixed1, fixed2).toFloat());
	EXPECT_EQ(fixed1.toFloat(), Fixed::min(fixed2, fixed1).toFloat());
	EXPECT_EQ(fixed2.toFloat(), Fixed::max(fixed1, fixed2).toFloat());
	EXPECT_EQ(fixed2.toFloat(), Fixed::max(fixed2, fixed1).toFloat());
}

TEST(FixedTest, TestMix) {
	float	float1(1.23f);
	float	float2(2.34f);
	Fixed	fixed1(float1);
	Fixed	fixed2(float2);

	EXPECT_NEAR(
		(fixed1 + fixed2 - fixed1 * fixed2 / fixed1).toFloat(),
		(float1 + float2 - float1 * float2 / float1),
		0.01
	);
	float	float3(4.321f);
	float	float4(3.210f);
	Fixed	fixed3(float3);
	Fixed	fixed4(float4);
	EXPECT_NEAR(
		(fixed3 + fixed4 - fixed3 * fixed4 / fixed3).toFloat(),
		(float3 + float4 - float3 * float4 / float3),
		0.01
	);
}
