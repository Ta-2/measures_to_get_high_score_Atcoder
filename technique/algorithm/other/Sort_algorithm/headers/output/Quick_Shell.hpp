/**
 * ※このファイル単体では動作しません。Sort.cppにincludeして使用してください。
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // 初期データの表示
    // Sort.showArray(vec10.begin(), vec10.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[QUICK_SHELL SORT]" << '\n';

    auto start10 = std::chrono::system_clock::now();
    //クイック・挿入ソート実施
    Sort.Quick_Shell(vec10.begin(), vec10.end(), false, false);
    auto end10 = std::chrono::system_clock::now();

    std::cout << "\nQuick_Shell_Sort が完了しました。\n";

    auto time10 = std::chrono::duration_cast<std::chrono::milliseconds>(end10 - start10).count();
    std::cout << "Quick_Shell_Sort: " << time10 <<"ms\n\n";