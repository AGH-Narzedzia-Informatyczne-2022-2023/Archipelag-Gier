using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    GameManager man;

    //Shot
    [SerializeField] private float cooldownShot = 3.0f;
    private float timerShot = 1f; //setTimer
    [SerializeField] private float speedShot = 8f;
    [SerializeField] private Vector3 translationShot;
    [SerializeField] private GameObject bulletShot;

    //Points
    [SerializeField] private int points;

    private void Start()
    {
        man = FindObjectOfType<GameManager>();        
        if(man == null)
        {
            Debug.Log("Brakuje GameManager");
            Destroy(gameObject);
        }
        man.AddEnemy(this);
    }

    private void Update()
    {
        //      --- Shot ---
        if (timerShot > 0) timerShot -= Time.deltaTime;
        if (timerShot < 0.1f) Shot();
        //print(timerShot);
    }

    private void Shot()
    {
        timerShot = cooldownShot;
        Vector3 positionSpawn = transform.position + translationShot;
        GameObject B = Instantiate(bulletShot, positionSpawn, Quaternion.identity) as GameObject;
        B.GetComponent<Bullet>().setShot(speedShot);
    }

    public void Step(Vector3 movement)
    {
        transform.position += movement;
        
        // Sprawdü czy przy úcianie
        if (transform.position.x < -7f || transform.position.x > 7f) man.nextToWall();
    }

    private void setTimer(float timerShot)
    {
        this.timerShot = timerShot;
    }

    private void OnDestroy()
    {
        man.RemoveEnemy(this);
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        //Debug.Log(collision.gameObject.tag);
        if (collision.gameObject.CompareTag("Bullet"))
        {
            Destroy(collision.gameObject);
            Destroy(gameObject);
        }
    }
}
