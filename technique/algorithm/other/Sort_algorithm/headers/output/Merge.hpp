/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // �����f�[�^�̕\��
    // Sort.showArray(vec4.begin(), vec4.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[MERGE SORT]" << '\n';

    auto start4 = std::chrono::system_clock::now();
    //�}�[�W�\�[�g���{
    Sort.Merge(vec4.begin(), vec4.end(), false);
    auto end4 = std::chrono::system_clock::now();
    std::cout << "\nMerge_Sort ���������܂����B\n";

    auto time4 = std::chrono::duration_cast<std::chrono::milliseconds>(end4 - start4).count();
    std::cout << "Merge_Sort: " << time4 <<"ms\n\n";