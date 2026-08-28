WITH collected AS
(
    SELECT
        m.machine_id,
        m.process_id,
        MAX(CASE 
                WHEN m.activity_type = 'start' 
                THEN m.timestamp
        END) AS start_time,
        MAX(CASE 
                WHEN m.activity_type = 'end' 
                THEN m.timestamp
        END) AS end_time
    FROM Activity m
    GROUP BY m.machine_id, m.process_id
)

SELECT
    machine_id,
    ROUND(AVG(end_time - start_time), 3) AS processing_time
FROM collected
GROUP BY machine_id
ORDER BY machine_id;