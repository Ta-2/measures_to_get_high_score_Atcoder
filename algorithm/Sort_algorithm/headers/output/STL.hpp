/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // �����f�[�^�̕\��
    // Sort.showArray(vec0.begin(), vec0.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[STL SORT]" << '\n';

    auto start0 = std::chrono::system_clock::now();
    //�W���\�[�g���{
    std::sort(vec0.begin(), vec0.end());
    auto end0 = std::chrono::system_clock::now();

    // for(auto &e : vec0) std::cout << e << ' ';

    std::sort(rev_vec0.rbegin(), rev_vec0.rend());

    std::cout << "\nSTL_Sort(�) ���������܂����B\n";

    auto time0 = std::chrono::duration_cast<std::chrono::milliseconds>(end0 - start0).count();
    std::cout << "STL_Sort: " << time0 <<"ms\n\n";