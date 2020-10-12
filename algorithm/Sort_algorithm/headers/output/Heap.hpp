/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // �����f�[�^�̕\��
    // Sort.showArray(vec7.begin(), vec7.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[HEAP SORT]" << '\n';

    auto start7 = std::chrono::system_clock::now();
    //�q�[�v�\�[�g���{
#ifdef HEAP_Con
    Sort.Heap(vec7, false);
#endif
#ifdef HEAP_Itr
    Sort.Heap_itr(vec7.begin(), vec7.end(), false);
#endif
    auto end7 = std::chrono::system_clock::now();

    std::cout << "\nHeap_Sort ���������܂����B\n";

    auto time7 = std::chrono::duration_cast<std::chrono::milliseconds>(end7 - start7).count();
    std::cout << "Heap_Sort: " << time7 <<"ms\n\n";