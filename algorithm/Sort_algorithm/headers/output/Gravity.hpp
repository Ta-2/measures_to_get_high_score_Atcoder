/**
 * �����̃t�@�C���P�̂ł͓��삵�܂���BSort.cpp��include���Ďg�p���Ă��������B
*/

#pragma once

/*-----------------------------------------------------------*/
    // std::cout << "[INIT DATA]" << '\n';
    // // �����f�[�^�̕\��
    // Sort.showArray(vec11.begin(), vec11.end());
    // std::cout << '\n' << '\n';

    // std::cout << "[GRAVITY SORT]" << '\n';

    auto start11 = std::chrono::system_clock::now();
    //�O���r�e�B�[�\�[�g���{
    Vec11 = Sort.Gravity(vec11);
    auto end11 = std::chrono::system_clock::now();

    // for(auto it = Vec11.end() - 1, End = Vec11.begin() - 1; it != End; --it) std::cout << *it << ' ';

    std::cout << "\nGravity_Sort ���������܂����B\n";

    auto time11 = std::chrono::duration_cast<std::chrono::milliseconds>(end11 - start11).count();
    std::cout << "Gravity_Sort: " << time11 <<"ms\n\n";