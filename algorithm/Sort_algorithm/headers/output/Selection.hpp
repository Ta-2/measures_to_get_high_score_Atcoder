/**
 * ※このファイル単体では動作しません。Sort.cppにincludeして使用してください。
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // 初期データの表示
    // Sort.showArray(vec2.begin(), vec2.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[SELECTION SORT]" << '\n';

    auto start2 = std::chrono::system_clock::now();
    //選択ソート実施
    Sort.Selection(vec2.begin(), vec2.end(), false, false, false);
    auto end2 = std::chrono::system_clock::now();

    auto time2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count();
    std::cout << "Selection_Sort: " << time2 <<"ms\n\n";