using System;
using System.Runtime.InteropServices;
using UnityEngine;

public static class MachineLearning
{
    [DllImport("TestDLLCPP")]
    private static extern IntPtr LoadLinearyClassifModel();

    [DllImport("TestDLLCPP")]
    private static extern IntPtr SetEntries(IntPtr ptr, float[] af, int size, int offset);

    [DllImport("TestDLLCPP")]
    private static extern IntPtr SetResult(IntPtr ptr, float[] af);

    [DllImport("TestDLLCPP")]
    private static extern IntPtr SetBiais(IntPtr ptr, float f);

    [DllImport("TestDLLCPP")]
    private static extern IntPtr SetStep(IntPtr ptr, float f);

    [DllImport("TestDLLCPP")]
    private static extern IntPtr InitW(IntPtr ptr);

    [DllImport("TestDLLCPP")]
    private static extern IntPtr GetValueResultLineary(IntPtr ptr);

    [DllImport("TestDLLCPP")]
    private static extern int GetLengthResultLineary(IntPtr ptr);

    [DllImport("TestDLLCPP")]
    public static extern void DeleteLineary(IntPtr ptr);

    public static IntPtr LoadLinearyClassifModel(float[,] _entries, float[] _results, float _step, float _biais)
    {
        IntPtr ptr = LoadLinearyClassifModel();

        int row = _entries.GetLength(0);
        int column = _entries.GetLength(1);
        int size = row * column;

        float[] array = new float[size];

        for(int i=0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                array[i + j * row] = _entries[i, j];
            }
        }

        SetEntries(ptr, array, size, column);
        SetResult(ptr, _results);
        SetBiais(ptr, _biais);
        SetStep(ptr, _step);
        InitW(ptr);

        return ptr;
    }

    public static float[] GetResultLineary(IntPtr ptr)
    {
        IntPtr ptrResult = GetValueResultLineary(ptr);

        int sizeArray = GetLengthResultLineary(ptr);

        float[] array = new float[sizeArray];

        Marshal.Copy(ptrResult, array, 0, sizeArray);

        return array;
    }

}
