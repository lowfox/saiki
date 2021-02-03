// saiki_test.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
/// sakamoto
/*

再帰関数が有効なアルゴリズム(簡素かつ明快な記述ができる）
・部分和問題
・数独ソルバー
・グラフ上の探索

フィボナッチ数列はfor文でもできるため、再帰の必要性が薄い


*/
#include <iostream>
#include <vector>
int func(int n) {
    if (n == 0) {
        return 0;
    }
    return n + func(n - 1);
}

int fibo(int n) {
    //ベースケース
    if (n == 0) {
        return 0;
    }else if(n==1){
        return 1;
    }
    //再帰呼び出し
    return fibo(n - 1) + fibo(n - 2);

}


long long fibo(int n, std::vector<long long>& memo) {
    //メモ化再帰(動的計画法）
    if (memo.at(n) == -1) {
    //ベースケース
        if (n == 0) {
            memo.at(n) = 0;
        }
        else if (n == 1) {
            memo.at(n) = 1;
        }
        else {
            memo.at(n) = fibo(n - 1, memo) + fibo(n - 2, memo);
        }

    }
    return memo.at(n);
}

int main()
{
    std::vector<long long> memo(50,-1);
    for (int n = 0; n < 50; ++n) {
        //std::cout << n << " までの和 = " << func(n) << std::endl;
        std::cout << n << " 項目の値： " << fibo(n,memo) << std::endl;
    }
}


// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
