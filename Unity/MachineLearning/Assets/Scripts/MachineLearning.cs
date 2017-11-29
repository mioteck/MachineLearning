using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;

public class MachineLearning : MonoBehaviour {

    [DllImport("MLLib_Unity", EntryPoint = "testdll")]
    static extern int simple_pow(int a);

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update ()
    {
		if (Input.GetKeyDown(KeyCode.P))
        {
            Debug.Log(simple_pow(10));
        }
	}
}
