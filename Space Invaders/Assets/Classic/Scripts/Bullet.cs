using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{

    //Shot
    [SerializeField] private float directY = 1f;
    [SerializeField] private float flySpeed = 1f;
    [SerializeField] private float maxY;
    
    public void setShot(float flySpeed)
    {
        this.flySpeed = flySpeed;
    }
    
    private void Update()
    {
        transform.position += new Vector3(0, 1, 0) * directY * flySpeed * Time.deltaTime;
        if (transform.position.y > maxY || transform.position.y < (-1) * maxY) Destroy(gameObject);
    }

    private void OnDestroy()
    {
        Debug.Log("BOOM");
    }
}
