/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // �����f�[�^�̕\��
    // Sort.showArray(vec1.begin(), vec1.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[BUBBLE SORT]" << '\n';

    auto start1 = std::chrono::system_clock::now();
    //�o�u���\�[�g���{
    Sort.Bubble(vec1.begin(), vec1.end(), false, false, false);
    auto end1 = std::chrono::system_clock::now();

    auto time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count();
    std::cout << "Bubble_Sort: " << time1 <<"ms\n\n";
