#pragma once

#include <vector>

namespace kya{

    //二分ヒープクラス
    template<class Ty>
    class Binary_Heap{
    protected:

        //ヒープの要素を格納する配列
        std::vector<Ty> heap;


        //ヒープに値vを挿入
        void push(Ty v){
            heap.push_back(v);              //最後尾に値追加

            int i = (int)heap.size() - 1;   //値の現在のノード番号(初期値は最後尾)

            while (i > 0){//大小比較

                int parent = (i - 1) / 2;       //親のノード番号

                if (heap[parent] >= v){
                    //逆転しなかったら、「逆転しなくなった時点のノード番号を保持して」ループを抜ける
                    break;
                }

                heap[i] = heap[parent];        //自分のノードを親の値に
                i = parent;                    //自分は元々親のいたノードに行く
            }

            //引数vはこのノードに格納される
            heap[i] = v;

            return;
        }


        //ヒープの最大値を得る(ヒープが空の時は-1を返す)
        Ty top(){
            return !heap.empty() ? heap[0] : -1;
        }


        //ヒープの最大値を削除(してヒープを組み直す)
        void pop(){
            if (heap.empty()) return;       //ヒープが空の時は何もしない

            Ty v = heap.back();            //ルートにこれから持ってくる値(ヒープの最後尾)

            heap.pop_back();                //最大値(ルート)の削除(最大値を得たい時はpopを呼び出す「前に」topで得る)

            int i = 0;                      //根から降ろしていく

            while (i * 2 + 1 < (int)heap.size()) {
                int child1 = i * 2 + 1;
                int child2 = i * 2 + 2;
                //子供同士を比較して大きい方をchild1とする
                if (child2 < (int)heap.size() && heap[child1] < heap[child2]){
                    child1 = child2;
                }

                if (heap[child1] <= v){
                    //逆転しなかったら、「逆転しなくなった時点のノード番号を保持して」ループを抜ける
                    break;
                }

                heap[i] = heap[child1];         //自分のノードを子の値に
                i = child1;                     //自分は元々子のいたノードに行く
            }

            //元ヒープの最後尾はこのノードに格納され、組み直しが完了する
            heap[i] = v;

            return;
        }
    };

}