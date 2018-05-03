using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rotator : MonoBehaviour {

	int flag=0;
	void Update () 
	{
		if (flag == 0) {
			transform.Rotate (new Vector3 (15, 30, 45) * Time.deltaTime);
		}
	}
	private void OnTriggerEnter(Collider other)
	{
		if (other.name =="Player") {
			Destroy(gameObject);
			flag = 1;
		}
	}
}
