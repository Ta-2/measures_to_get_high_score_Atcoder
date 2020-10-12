/**
 * ※このファイル単体では動作しません。Sort.cppにincludeして使用してください。
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // 初期データの表示
    // Sort.showArray(vec0.begin(), vec0.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[STL SORT]" << '\n';

    auto start0 = std::chrono::system_clock::now();
    //標準ソート実施
    std::sort(vec0.begin(), vec0.end());
    auto end0 = std::chrono::system_clock::now();

    // for(auto &e : vec0) std::cout << e << ' ';

    std::sort(rev_vec0.rbegin(), rev_vec0.rend());

    std::cout << "\nSTL_Sort(基準) が完了しました。\n";

    auto time0 = std::chrono::duration_cast<std::chrono::milliseconds>(end0 - start0).count();
    std::cout << "STL_Sort: " << time0 <<"ms\n\n";