/**
 * ※このファイル単体では動作しません。Sort.cppにincludeして使用してください。
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // 初期データの表示
    // Sort.showArray(vec8.begin(), vec8.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[INTRO SORT]" << '\n';

    auto start8 = std::chrono::system_clock::now();
    //クイックソート実施
    Sort.Intro(vec8.begin(), vec8.end(), false);
    auto end8 = std::chrono::system_clock::now();

    std::cout << "\nIntro_Sort が完了しました。\n";

    auto time8 = std::chrono::duration_cast<std::chrono::milliseconds>(end8 - start8).count();
    std::cout << "Intro_Sort: " << time8 <<"ms\n\n";