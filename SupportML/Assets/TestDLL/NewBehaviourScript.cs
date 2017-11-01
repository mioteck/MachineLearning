using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;
using System;

public class NewBehaviourScript : MonoBehaviour {
    public GameObject container;

    public GameObject plane;

    // Use this for initialization
    void Start() {
        int childCount = container.transform.childCount;

        float[,] entry = new float[childCount,2];
        float[] result = new float[childCount];

        for(int i=0; i<childCount; i++)
        {
            Transform t = container.transform.GetChild(i);

            entry[i,0] = t.position.x;
            entry[i, 1] = t.position.y;

            result[i] = (t.position.y < 0) ? -1 : 1;
        }

        IntPtr ptr = MachineLearning.LoadLinearyClassifModel(entry, result, 0.01f, 0.5f);
        float[] resolveValue = MachineLearning.GetResultLineary(ptr);
        MachineLearning.DeleteLineary(ptr);
    }
	
	// Update is called once per frame
	void Update () {
		
	}
}
