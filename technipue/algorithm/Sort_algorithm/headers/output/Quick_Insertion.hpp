/**
 * ※このファイル単体では動作しません。Sort.cppにincludeして使用してください。
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // 初期データの表示
    // Sort.showArray(vec6.begin(), vec6.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[QUICK_INSERTION SORT]" << '\n';

    auto start6 = std::chrono::system_clock::now();
    //クイック・挿入ソート実施
    Sort.Quick_Insertion(vec6.begin(), vec6.end(), false);
    auto end6 = std::chrono::system_clock::now();

    std::cout << "\nQuick_Insertion_Sort が完了しました。\n";

    auto time6 = std::chrono::duration_cast<std::chrono::milliseconds>(end6 - start6).count();
    std::cout << "Quick_Insertion_Sort: " << time6 <<"ms\n\n";