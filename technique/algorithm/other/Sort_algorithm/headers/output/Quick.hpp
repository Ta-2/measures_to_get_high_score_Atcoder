/**
 * ※このファイル単体では動作しません。Sort.cppにincludeして使用してください。
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // 初期データの表示
    // Sort.showArray(vec5.begin(), vec5.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[QUICK SORT]" << '\n';

    auto start5 = std::chrono::system_clock::now();
    //クイックソート実施
    Sort.Quick(vec5.begin(), vec5.end(), false);
    auto end5 = std::chrono::system_clock::now();
    std::cout << "\nQuick_Sort が完了しました。\n";

    auto time5 = std::chrono::duration_cast<std::chrono::milliseconds>(end5 - start5).count();
    std::cout << "Quick_Sort: " << time5 <<"ms\n\n";