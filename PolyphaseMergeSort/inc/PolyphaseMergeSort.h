#pragma once
#include<string>
#include<fstream>
#include<QuickSort.h>

class PolyphaseMergeSort
{
private:
    const int memory;
    int* mas;
    int mSize; //количество чисел в файле input
    std::string mPathInputFile;
    bool outputFlag;

public:
    explicit PolyphaseMergeSort(const std::string& pathInputFile) : memory{4}, mSize{0}, mPathInputFile{pathInputFile}
    {
        mas = new int[memory];
        this->createTmpFiles();
    }

    void sort()
    {
        this->sortAndDistributeByTmpFiles();
        bool anotherPairFiles = false; //0-считываем из 0 и 1; 1-считываем из 2 и 3
        int curSize = memory / 2;
        while (curSize < mSize)
        {
            this->inFilesSort(anotherPairFiles, curSize);
            curSize *= 2;
            anotherPairFiles = !anotherPairFiles;
        }
        outputFlag = anotherPairFiles;
    }

    bool getOutputFlag()
    {
        return outputFlag;
    }

private:
    void createTmpFiles()
    {
        for (int i = 0; i < memory; ++i)
            std::ofstream("files/tmp" + std::to_string(i) + ".txt").close();
    }

    void writeToTmpFile(int indexFile, int count /*количество которое надо записать*/)
    {
        std::ofstream tmpFile("files/tmp" + std::to_string(indexFile) + ".txt", std::ios::app);
        for (int i = 0; i < count; ++i)
        {
            tmpFile << mas[i] << "\n";
        }
    }

    void sortAndDistributeByTmpFiles()
    {
        std::ifstream input;
        input.open(mPathInputFile);
        std::string line;
        int index = 0;
        bool anotherFile = false; //Отвечает за посменную запись
        while (!input.eof())
        {
            if (mSize % memory == 0 && mSize != 0)
            {
                quick_sort(mas, 0, index - 1);
                if (!anotherFile)
                    this->writeToTmpFile(0, index);
                else
                    this->writeToTmpFile(1, index);
                anotherFile = !anotherFile;
                index = 0;
            }
            std::getline(input, line);
            if (!line.empty())
            {
                mas[index] = std::stoi(line);
                ++index;
                ++mSize;
            }
        }
        quick_sort(mas, 0, index - 1);
        if (!anotherFile)
            this->writeToTmpFile(0, index);
        else
            this->writeToTmpFile(1, index);
    }

    void inFilesSort(bool anotherPairFiles, int curSize)
    {
        std::string firstVal;
        std::string secondVal;
        bool anotherFile = false;
        int indexFile;

        if (!anotherPairFiles)
            indexFile = 0;
        else
            indexFile = 2;

        std::string pathFirstReader = "files/tmp" + std::to_string(indexFile) + ".txt";
        std::string pathSecondReader = "files/tmp" + std::to_string(indexFile + 1) + ".txt";
        std::string pathFirstWriter = "files/tmp" + std::to_string((indexFile + 2) % 4) + ".txt";
        std::string pathSecondWriter = "files/tmp" + std::to_string((indexFile + 2) % 4 + 1) + ".txt";
        std::ifstream firstReader(pathFirstReader);
        std::ifstream secondReader(pathSecondReader);
        std::ofstream firstWriter(pathFirstWriter);
        std::ofstream secondWriter(pathSecondWriter);

        int pointer1 = 0;
        int pointer2 = 0;
        firstReader >> firstVal;
        secondReader >> secondVal;
        while (!firstReader.eof())
        {
            //основная часть
            while (!secondReader.eof())
            {
                if (std::stoi(firstVal) > std::stoi(secondVal))
                {
                    ++pointer2;
                    if (!anotherFile)
                        firstWriter << secondVal << "\n";
                    else
                        secondWriter << secondVal << "\n";
                }
                else
                {
                    ++pointer1;
                    if (!anotherFile)
                        firstWriter << firstVal << "\n";
                    else
                        secondWriter << firstVal << "\n";
                    break;
                }
                secondReader >> secondVal;

                //если pointer2 прошел curSize раньше
                if (pointer2 == curSize)
                {
                    while (pointer1 < curSize)
                    {
                        if (!anotherFile)
                            firstWriter << firstVal << "\n";
                        else
                            secondWriter << firstVal << "\n";
                        ++pointer1;
                        firstReader >> firstVal;
                    }
                    anotherFile = !anotherFile;
                    pointer1 = 0;
                    pointer2 = 0;
                }
            }
            //если второй файл закончился раньше
            if (secondReader.eof())
            {
                if (pointer1 == curSize)
                {
                    anotherFile = !anotherFile;
                    pointer1 = 0;
                }

                if (!anotherFile)
                    firstWriter << firstVal << "\n";
                else
                    secondWriter << firstVal << "\n";
                ++pointer1;
            }

            //если pointer1 прошел curSize раньше
            if (pointer1 == curSize && !secondReader.eof())
            {
                while (pointer2 < curSize && !secondReader.eof())
                {
                    if (!anotherFile)
                        firstWriter << secondVal << "\n";
                    else
                        secondWriter << secondVal << "\n";
                    ++pointer2;
                    secondReader >> secondVal;
                }
                anotherFile = !anotherFile;
                pointer1 = 0;
                pointer2 = 0;
            }

            firstReader >> firstVal;
        }
        //если первый файл закончился, а второй нет
        if (firstReader.eof() && !secondReader.eof())
        {
            while (!secondReader.eof())
            {
                if (pointer2 == curSize)
                {
                    anotherFile = !anotherFile;
                    pointer2 = 0;
                }
                if (!anotherFile)
                    firstWriter << secondVal << "\n";
                else
                    secondWriter << secondVal << "\n";
                ++pointer2;
                secondReader >> secondVal;
            }
        }

        firstReader.close();
        firstWriter.close();
        secondReader.close();
        secondWriter.close();
        firstVal.clear();
        secondVal.clear();
    }
};