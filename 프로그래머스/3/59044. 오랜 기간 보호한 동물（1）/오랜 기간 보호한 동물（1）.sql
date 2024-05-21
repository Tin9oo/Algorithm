-- 코드를 입력하세요
SELECT ANIMAL_INS.NAME, ANIMAL_INS.DATETIME
FROM ANIMAL_INS
WHERE ANIMAL_INS.ANIMAL_ID NOT IN (
    SELECT ANIMAL_OUTS.ANIMAL_ID
    FROM ANIMAL_OUTS
)
ORDER BY ANIMAL_INS.DATETIME
LIMIT 0, 3;















select a.name, a.datetime
from animal_ins a
left join animal_outs b
    on a.animal_id=b.animal_id
where b.animal_id is null
order by a.datetime
limit 3
;