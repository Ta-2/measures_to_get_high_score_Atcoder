/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // �����f�[�^�̕\��
    // Sort.showArray(vec3.begin(), vec3.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[INSERTION SORT]" << '\n';

    auto start3 = std::chrono::system_clock::now();
    //�}���\�[�g���{
    Sort.Insertion(vec3.begin(), vec3.end(), false, false, false);
    auto end3 = std::chrono::system_clock::now();

    auto time3 = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3).count();
    std::cout << "Insertion_Sort: " << time3 <<"ms\n\n";