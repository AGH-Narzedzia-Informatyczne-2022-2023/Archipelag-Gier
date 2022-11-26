using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    private delegate void Managers();

    //Enemy Manager
    [SerializeField] private List<GameObject> listEnemyPrefabs;
    private List<Enemy> livingEnemies = new List<Enemy>();
    //Przesuwanie przeciwników
    private Managers EnemiesMove;
    private float moveCooldown = 3f;
    private float moveTimer = 3f;
    private int moveX = 1;
    private int moveY = -1;
    //-- KrawedŸ
    private bool nextWall = false;
    private bool stillWall = false;

    private void Update()
    {
        EnemyManager();
    }
    private void OnEnable()
    {
        EnemiesMove += EnemiesMoveX;
    }

    private void OnDisable()
    {
        EnemiesMove -= EnemiesMoveX;
        EnemiesMove -= EnemiesMoveY;
    }

    public void AddEnemy(Enemy e)
    {
        livingEnemies.Add(e);
    }

    public void RemoveEnemy(Enemy e)
    {
        livingEnemies.Remove(e);
    }

    private void EnemyManager()
    {
        moveTimer -= Time.deltaTime;
        if (moveTimer < 0.01f)
        {
            moveTimer = moveCooldown;
            if (EnemiesMove != null) EnemiesMove();
        }
    }

    public void nextToWall()
    {
        nextWall = true;
    }

    private void EnemiesMoveX()
    {
        Vector3 step = new Vector3(moveX, 0, 0);
        print(step);
        foreach (Enemy e in livingEnemies)
        {
            if(e != null) e.Step(step);
        }
        if (stillWall)
        {
            nextWall = false;
            stillWall = false;
        }
        if (nextWall)
        {
            moveTimer = 0.3f;
            EnemiesMove += EnemiesMoveY;
            EnemiesMove -= EnemiesMoveX;
        }
    }
    private void EnemiesMoveY()
    {
        Vector3 step = new Vector3(0, moveY, 0);
        print(step);
        foreach (Enemy e in livingEnemies)
        {
            e.Step(step);
        }
        moveX *= -1;
        stillWall = true;
        EnemiesMove += EnemiesMoveX;
        EnemiesMove -= EnemiesMoveY;
    }
}
