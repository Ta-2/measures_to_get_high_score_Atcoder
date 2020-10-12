/**
 * ※このファイル単体では動作しません。Sort.cppにincludeして使用してください。
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // 初期データの表示
    // Sort.showArray(vec9.begin(), vec9.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[SHELL SORT]" << '\n';

    auto start9 = std::chrono::system_clock::now();
    //シェルソート実施
    Sort.Shell(vec9.begin(), vec9.end(), false);
    auto end9 = std::chrono::system_clock::now();
    std::cout << "\nShell_Sort が完了しました。\n";

    auto time9 = std::chrono::duration_cast<std::chrono::milliseconds>(end9 - start9).count();
    std::cout << "Shell_Sort: " << time9 <<"ms\n\n";