/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // �����f�[�^�̕\��
    // Sort.showArray(vec10.begin(), vec10.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[QUICK_SHELL SORT]" << '\n';

    auto start10 = std::chrono::system_clock::now();
    //�N�C�b�N�E�}���\�[�g���{
    Sort.Quick_Shell(vec10.begin(), vec10.end(), false, false);
    auto end10 = std::chrono::system_clock::now();

    std::cout << "\nQuick_Shell_Sort ���������܂����B\n";

    auto time10 = std::chrono::duration_cast<std::chrono::milliseconds>(end10 - start10).count();
    std::cout << "Quick_Shell_Sort: " << time10 <<"ms\n\n";