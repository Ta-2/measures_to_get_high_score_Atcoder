/**
 * ※このファイル単体では動作しません。Sort.cppにincludeして使用してください。
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // 初期データの表示
    // Sort.showArray(vec4.begin(), vec4.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[MERGE SORT]" << '\n';

    auto start4 = std::chrono::system_clock::now();
    //マージソート実施
    Sort.Merge(vec4.begin(), vec4.end(), false);
    auto end4 = std::chrono::system_clock::now();
    std::cout << "\nMerge_Sort が完了しました。\n";

    auto time4 = std::chrono::duration_cast<std::chrono::milliseconds>(end4 - start4).count();
    std::cout << "Merge_Sort: " << time4 <<"ms\n\n";