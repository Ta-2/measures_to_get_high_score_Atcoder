/**
 * ※このファイル単体では動作しません。Sort.cppにincludeして使用してください。
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // 初期データの表示
    // Sort.showArray(vec00.begin(), vec00.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[STL_STABLE SORT]" << '\n';

    auto start00 = std::chrono::system_clock::now();
    //標準(安定)ソート実施
    std::sort(vec00.begin(), vec00.end());
    auto end00 = std::chrono::system_clock::now();

    std::cout << "\nSTL_stable_Sort が完了しました。\n";

    auto time00 = std::chrono::duration_cast<std::chrono::milliseconds>(end00 - start00).count();
    std::cout << "STL_stable_Sort: " << time00 <<"ms\n\n";