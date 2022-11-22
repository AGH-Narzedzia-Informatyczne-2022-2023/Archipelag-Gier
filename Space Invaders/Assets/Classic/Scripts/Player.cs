using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class Player : MonoBehaviour
{
    private SpaceInput inputs;

    [SerializeField]private float maxX = 7f, minX = -7f;
    [SerializeField]private float movementSpeed = 1.0f;

    [SerializeField]private float cooldownShot = 1.0f, timerShot = 0.3f;
    [SerializeField]private float speedShot = 8f;
    [SerializeField]private Vector3 shotPosition;
    [SerializeField]private GameObject bulletShot;

    private void Awake()
    {
        inputs = new SpaceInput();
    }

    private void OnEnable()
    {
        inputs.Enable();
    }

    private void OnDisable()
    {
        inputs.GameClassic.Shot.performed -= _=> Shot();
        inputs.Disable();
    }

    private void Start()
    {
        //rb = GetComponent<Rigidbody2D>();
        inputs.GameClassic.Shot.performed += _=>Shot();
    }

    
    private void Update()
    {
        //      --- Shot cooldown ---
        if (timerShot > 0) timerShot -= Time.deltaTime;
        //print(timerShot);
    }

    private void FixedUpdate()
    {
        Move();
    }

    private void Move()
    {
        float actualX = transform.position.x;
        float move = inputs.GameClassic.Move.ReadValue<float>();
        //print(move);
        if (move == 0) return;
        if (move < 0 && actualX < minX + 0.1f) return;
        if (move > 0 && actualX > maxX - 0.1f) return;
        //rb.AddForce(new Vector2(1,0) * movementSpeed * move);
        transform.position += new Vector3(1, 0, 0) * move * movementSpeed * Time.deltaTime;
    }

    private void Shot()
    {
        if (timerShot > 0.1f) return;
        timerShot = cooldownShot;
        Vector3 positionSpawn = transform.position + shotPosition;
        GameObject B = Instantiate(bulletShot, positionSpawn, Quaternion.identity) as GameObject;
        B.GetComponent<Bullet>().setShot(speedShot);
    }
}
