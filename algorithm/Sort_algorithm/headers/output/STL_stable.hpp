/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // �����f�[�^�̕\��
    // Sort.showArray(vec00.begin(), vec00.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[STL_STABLE SORT]" << '\n';

    auto start00 = std::chrono::system_clock::now();
    //�W��(����)�\�[�g���{
    std::sort(vec00.begin(), vec00.end());
    auto end00 = std::chrono::system_clock::now();

    std::cout << "\nSTL_stable_Sort ���������܂����B\n";

    auto time00 = std::chrono::duration_cast<std::chrono::milliseconds>(end00 - start00).count();
    std::cout << "STL_stable_Sort: " << time00 <<"ms\n\n";