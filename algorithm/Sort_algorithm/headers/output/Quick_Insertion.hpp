/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // �����f�[�^�̕\��
    // Sort.showArray(vec6.begin(), vec6.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[QUICK_INSERTION SORT]" << '\n';

    auto start6 = std::chrono::system_clock::now();
    //�N�C�b�N�E�}���\�[�g���{
    Sort.Quick_Insertion(vec6.begin(), vec6.end(), false);
    auto end6 = std::chrono::system_clock::now();

    std::cout << "\nQuick_Insertion_Sort ���������܂����B\n";

    auto time6 = std::chrono::duration_cast<std::chrono::milliseconds>(end6 - start6).count();
    std::cout << "Quick_Insertion_Sort: " << time6 <<"ms\n\n";