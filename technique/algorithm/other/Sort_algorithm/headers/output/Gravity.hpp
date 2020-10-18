/**
 * ※このファイル単体では動作しません。Sort.cppにincludeして使用してください。
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // 初期データの表示
    // Sort.showArray(vec11.begin(), vec11.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[GRAVITY SORT]" << '\n';

    auto start11 = std::chrono::system_clock::now();
    //グラビティーソート実施
    Vec11 = Sort.Gravity(vec11);
    auto end11 = std::chrono::system_clock::now();

    // for(auto it = Vec11.end() - 1, End = Vec11.begin() - 1; it != End; --it) std::cout << *it << ' ';

    std::cout << "\nGravity_Sort が完了しました。\n";

    auto time11 = std::chrono::duration_cast<std::chrono::milliseconds>(end11 - start11).count();
    std::cout << "Gravity_Sort: " << time11 <<"ms\n\n";