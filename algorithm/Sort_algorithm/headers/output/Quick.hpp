/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // �����f�[�^�̕\��
    // Sort.showArray(vec5.begin(), vec5.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[QUICK SORT]" << '\n';

    auto start5 = std::chrono::system_clock::now();
    //�N�C�b�N�\�[�g���{
    Sort.Quick(vec5.begin(), vec5.end(), false);
    auto end5 = std::chrono::system_clock::now();
    std::cout << "\nQuick_Sort ���������܂����B\n";

    auto time5 = std::chrono::duration_cast<std::chrono::milliseconds>(end5 - start5).count();
    std::cout << "Quick_Sort: " << time5 <<"ms\n\n";