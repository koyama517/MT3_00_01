#include <Novice.h>
#include <cmath>

const char kWindowTitle[] = "LD2A_06_コヤマタクミ";

struct Vector3 {
	float x;
	float y;
	float z;
};

Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;

	return result;
};

Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;

	return result;
};

Vector3 Multiply(float scalar, const Vector3& v) {
	Vector3 result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	result.z = v.z * scalar;

	return result;
}

float Dot(const Vector3& v1, const Vector3& v2){
	float result;

	return result = v1.x * v2.x + v1.y * v1.y + v1.z * v2.z;

};

float Length(const Vector3& v) {
	
	return sqrt(Dot(v,v));
};

Vector3 Normalize(const Vector3& v) {

	float length = Length(v);
	Vector3 result;
	if (!length == 0)
	{
		result.x = v.x / length;
		result.y = v.y / length;
		result.z = v.z / length;
	}

	return result;

};

static const int kColumnWidht = 60;

void VecterScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x,y,"%0.2f",vector.x);
	Novice::ScreenPrintf(x + kColumnWidht, y, "%0.2f",vector.y);
	Novice::ScreenPrintf(x + kColumnWidht * 2, y, "%0.2f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidht * 3, y, "%s",label);
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Vector3 v1{ 1.0f,3.0f,-5.0f };
	Vector3 v2{ 4.0f,-1.0f,2.0f };
	float k = { 4.0 };
	int kRowHeight = 20;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		Vector3 resultAdd = Add(v1, v2);
		Vector3 resultSubtract = Subtract(v1, v2);
		Vector3 resultMultiply = Multiply(k, v1);
		float resultDot = Dot(v1, v2);
		float resultLength = Length(v1);
		Vector3 resultNormalize = Normalize(v2);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		VecterScreenPrintf(0, 0, resultAdd, "  : Add");
		VecterScreenPrintf(0, kRowHeight, resultSubtract, "  : Subract");
		VecterScreenPrintf(0, kRowHeight * 2, resultMultiply, "  : Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3,"%.02f  : Dot",resultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%.02f  : Length", resultLength);
		VecterScreenPrintf(0, kRowHeight * 5, resultAdd, "  : Normalize");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
