/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // �����f�[�^�̕\��
    // Sort.showArray(vec8.begin(), vec8.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[INTRO SORT]" << '\n';

    auto start8 = std::chrono::system_clock::now();
    //�N�C�b�N�\�[�g���{
    Sort.Intro(vec8.begin(), vec8.end(), false);
    auto end8 = std::chrono::system_clock::now();

    std::cout << "\nIntro_Sort ���������܂����B\n";

    auto time8 = std::chrono::duration_cast<std::chrono::milliseconds>(end8 - start8).count();
    std::cout << "Intro_Sort: " << time8 <<"ms\n\n";