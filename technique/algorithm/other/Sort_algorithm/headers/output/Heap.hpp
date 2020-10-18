/**
 * ※このファイル単体では動作しません。Sort.cppにincludeして使用してください。
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // 初期データの表示
    // Sort.showArray(vec7.begin(), vec7.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[HEAP SORT]" << '\n';

    auto start7 = std::chrono::system_clock::now();
    //ヒープソート実施
#ifdef HEAP_Con
    Sort.Heap(vec7, false);
#endif
#ifdef HEAP_Itr
    Sort.Heap_itr(vec7.begin(), vec7.end(), false);
#endif
    auto end7 = std::chrono::system_clock::now();

    std::cout << "\nHeap_Sort が完了しました。\n";

    auto time7 = std::chrono::duration_cast<std::chrono::milliseconds>(end7 - start7).count();
    std::cout << "Heap_Sort: " << time7 <<"ms\n\n";