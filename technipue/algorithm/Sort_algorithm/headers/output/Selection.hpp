/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // �����f�[�^�̕\��
    // Sort.showArray(vec2.begin(), vec2.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[SELECTION SORT]" << '\n';

    auto start2 = std::chrono::system_clock::now();
    //�I���\�[�g���{
    Sort.Selection(vec2.begin(), vec2.end(), false, false, false);
    auto end2 = std::chrono::system_clock::now();

    auto time2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count();
    std::cout << "Selection_Sort: " << time2 <<"ms\n\n";