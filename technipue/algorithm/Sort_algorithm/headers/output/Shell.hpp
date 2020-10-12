/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // �����f�[�^�̕\��
    // Sort.showArray(vec9.begin(), vec9.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[SHELL SORT]" << '\n';

    auto start9 = std::chrono::system_clock::now();
    //�V�F���\�[�g���{
    Sort.Shell(vec9.begin(), vec9.end(), false);
    auto end9 = std::chrono::system_clock::now();
    std::cout << "\nShell_Sort ���������܂����B\n";

    auto time9 = std::chrono::duration_cast<std::chrono::milliseconds>(end9 - start9).count();
    std::cout << "Shell_Sort: " << time9 <<"ms\n\n";