/**
 * ※このファイル単体では動作しません。Sort.cppにincludeして使用してください。
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // 初期データの表示
    // Sort.showArray(vec1.begin(), vec1.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[BUBBLE SORT]" << '\n';

    auto start1 = std::chrono::system_clock::now();
    //バブルソート実施
    Sort.Bubble(vec1.begin(), vec1.end(), false, false, false);
    auto end1 = std::chrono::system_clock::now();

    auto time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count();
    std::cout << "Bubble_Sort: " << time1 <<"ms\n\n";
