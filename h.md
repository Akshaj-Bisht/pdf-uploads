# E-Learning Platform - Complete Documentation

## Problem Statement

Indian college students face significant challenges when preparing for exams and understanding course material. These challenges include:

1. **Limited access to previous year question papers (PYQs)**: Students struggle to find relevant PYQs that would help them understand exam patterns and important topics.

2. **Scattered learning resources**: Study materials are often scattered across different platforms, making it difficult for students to find all needed resources in one place.

3. **Lack of structured study guidance**: Without proper guidance, students often struggle to determine which topics to prioritize.

4. **Insufficient collaboration opportunities**: Many students study in isolation without benefiting from peer knowledge and support.

5. **Difficulty verifying content quality**: Students can't easily identify which notes or materials are most helpful or accurate.

The proposed e-learning platform aims to address these challenges by providing a centralized hub for accessing PYQs, notes, and curated YouTube playlists, as well as enabling students to form study groups and share resources.

## Process Model

The development of the e-learning platform will follow the **Incremental Model**, which combines elements of the waterfall model with an iterative approach. This model has been chosen for the following reasons:

1. It allows for early delivery of partial but functional products (increments)
2. Each increment can be evaluated by users, providing valuable feedback
3. Lower risk of overall project failure
4. Easier to manage changing requirements between increments

The process will involve the following phases for each increment:

1. **Requirements gathering and analysis**: Define specific requirements for the current increment
2. **Design**: Create detailed design for the functions to be implemented
3. **Implementation and unit testing**: Develop and test individual components
4. **Integration and system testing**: Combine components and test the integrated system
5. **Deployment**: Release the current increment to users
6. **Review and feedback**: Gather user feedback to inform the next increment

## Software Requirements Specification

### Functional Requirements

#### 1. User Management
- FR1.1: The system shall allow users to register using Google Sign-In.
- FR1.2: The system shall maintain user profiles with academic information.
- FR1.3: The system shall authenticate users before allowing access to materials.
- FR1.4: The system shall provide admin accounts with moderation capabilities.

#### 2. Study Material Management
- FR2.1: The system shall allow users to view PYQs, notes, and YouTube playlists.
- FR2.2: The system shall allow users to upload study materials.
- FR2.3: The system shall categorize study materials by subject, course, and type.
- FR2.4: The system shall allow users to like helpful materials.
- FR2.5: The system shall implement content moderation for uploaded materials.

#### 3. Study Group Management
- FR3.1: The system shall allow users to create study groups.
- FR3.2: The system shall allow users to join existing study groups.
- FR3.3: The system shall support public and invite-only group options.
- FR3.4: The system shall allow sharing of materials within groups.

#### 4. Search and Discovery
- FR4.1: The system shall provide a search function for finding materials.
- FR4.2: The system shall support filtering by subject, type, and relevance.
- FR4.3: The system shall display personalized recommendations based on user's academic stream.

### Non-Functional Requirements

#### 1. Performance
- NFR1.1: The system shall load search results within 3 seconds.
- NFR1.2: The system shall support at least 10,000 concurrent users.
- NFR1.3: The system shall compress uploaded files to optimize storage.

#### 2. Security
- NFR2.1: The system shall implement role-based access control.
- NFR2.2: The system shall encrypt sensitive user data.
- NFR2.3: The system shall validate all uploaded files to prevent malicious content.

#### 3. Usability
- NFR3.1: The system shall have a minimal, intuitive interface.
- NFR3.2: The system shall be fully responsive for mobile devices.
- NFR3.3: The system shall provide helpful error messages.

#### 4. Reliability
- NFR4.1: The system shall be available 99.5% of the time.
- NFR4.2: The system shall back up all data daily.
- NFR4.3: The system shall recover from failures within 30 minutes.

## Context Level Diagram

```
+---------------------------------------------------------------+
|                                                               |
|  +---------------+        +-----------------------+           |
|  |               |        |                       |           |
|  |  College      | -----> |                       |           |
|  |  Students     | <----- |                       |           |
|  |               |        |                       |           |
|  +---------------+        |                       |           |
|                           |                       |           |
|  +---------------+        |    E-Learning         |           |
|  |               |        |    Platform           |           |
|  |  Content      | -----> |                       |           |
|  |  Moderators   | <----- |                       |           |
|  |               |        |                       |           |
|  +---------------+        |                       |           |
|                           |                       |           |
|  +---------------+        |                       |           |
|  |               |        |                       |           |
|  |  System       | -----> |                       |           |
|  |  Administrators| <---- |                       |           |
|  |               |        |                       |           |
|  +---------------+        +-----------------------+           |
|                                                               |
+---------------------------------------------------------------+
```

## DFD Level 1

```
+----------------+       +---------------+        +---------------+
|                |       |               |        |               |
|  User          | ----> |  User         | -----> |  Study        |
|  Authentication|       |  Management   |        |  Material     |
|                | <---- |               | <----- |  Management   |
+----------------+       +---------------+        +---------------+
                              ^   |                     ^   |
                              |   |                     |   |
                              |   v                     |   v
                         +---------------+        +---------------+
                         |               |        |               |
                         |  Study Group  | <----> |  Search &     |
                         |  Management   |        |  Discovery    |
                         |               |        |               |
                         +---------------+        +---------------+
```

## DFD Level 2: Study Material Management

```
                     +-------------------+
                     |                   |
                     |  View Materials   |
                     |                   |
                     +-------------------+
                              ^
                              |
+----------------+    +---------------+    +----------------+
|                |    |               |    |                |
|  Upload        | -> |  Material     | <- |  Like/Rate     |
|  Materials     |    |  Database     |    |  Materials     |
|                |    |               |    |                |
+----------------+    +---------------+    +----------------+
                              ^
                              |
                     +-------------------+
                     |                   |
                     |  Moderate         |
                     |  Content          |
                     |                   |
                     +-------------------+
```

## Use Case Diagram

```
+----------------------------------------------------------------+
|                       E-Learning Platform                       |
|                                                                |
|  +--------+                                      +--------+    |
|  |        |                                      |        |    |
|  | Student| -- Register/Login -----------------> |        |    |
|  |        | -- View Study Materials -----------> |        |    |
|  |        | -- Upload Study Materials ---------> | System |    |
|  |        | -- Like/Rate Materials ------------> |        |    |
|  |        | -- Create/Join Study Groups -------> |        |    |
|  |        | -- Search for Materials -----------> |        |    |
|  +--------+                                      +--------+    |
|                                                      ^         |
|  +--------+                                          |         |
|  |        | -- Moderate Content -----------------    |         |
|  | Admin  | -- Manage Users ---------------------    |         |
|  |        | -- Handle Reports -------------------    |         |
|  +--------+                                                    |
|                                                                |
+----------------------------------------------------------------+
```

## Use Case Description

### Use Case: Upload Study Materials

**Actor**: Student

**Description**: This use case describes the process of a student uploading study materials to the platform.

**Preconditions**:
- Student must be registered and logged into the system.
- Student must have the study material file ready for upload.

**Main Flow**:
1. Student navigates to the "Upload Materials" section.
2. Student selects the material type (Notes, PYQ, etc.).
3. Student selects the subject and relevant course.
4. Student provides a title and description for the material.
5. Student uploads the file or YouTube link.
6. System validates the uploaded content.
7. System processes and stores the material.
8. System confirms successful upload.

**Alternative Flows**:
- A3: If validation fails, student is notified and prompted to modify the upload.
- A5: If file size exceeds limits, system prompts for compression or splitting.

**Postconditions**:
- Study material is stored in the system and available for other students to view.
- Student's upload count is updated in their profile.

## Data Dictionary

### User Table
| Field | Type | Description | Constraints |
|-------|------|-------------|-------------|
| UserID | Integer | Unique identifier for the user | Primary Key, Auto-increment |
| Email | String | User's email address | Unique, Not Null |
| Name | String | User's full name | Not Null |
| College | String | User's college name | Not Null |
| Stream | String | User's academic stream | Not Null |
| JoinDate | Date | Date when user joined | Default: Current Date |
| Role | Enum | User role (Student/Admin) | Default: Student |

### StudyMaterial Table
| Field | Type | Description | Constraints |
|-------|------|-------------|-------------|
| MaterialID | Integer | Unique identifier for material | Primary Key, Auto-increment |
| Title | String | Title of the material | Not Null |
| Description | Text | Detailed description | Nullable |
| Type | Enum | Type (Note, PYQ, Video) | Not Null |
| Subject | String | Related subject | Not Null |
| UploadDate | DateTime | When material was uploaded | Default: Current Time |
| FilePath | String | Path to stored file | Nullable |
| YouTubeLink | String | Link to YouTube video | Nullable |
| UploadedBy | Integer | UserID of uploader | Foreign Key |
| LikeCount | Integer | Number of likes | Default: 0 |

### StudyGroup Table
| Field | Type | Description | Constraints |
|-------|------|-------------|-------------|
| GroupID | Integer | Unique identifier for group | Primary Key, Auto-increment |
| GroupName | String | Name of the study group | Not Null |
| Description | Text | Description of group | Nullable |
| IsPublic | Boolean | Whether group is public | Default: True |
| CreatedBy | Integer | UserID of creator | Foreign Key |
| CreationDate | Date | When group was created | Default: Current Date |

### GroupMembership Table
| Field | Type | Description | Constraints |
|-------|------|-------------|-------------|
| MembershipID | Integer | Unique identifier | Primary Key, Auto-increment |
| GroupID | Integer | ID of the group | Foreign Key |
| UserID | Integer | ID of the user | Foreign Key |
| JoinDate | Date | When user joined group | Default: Current Date |

### MaterialLikes Table
| Field | Type | Description | Constraints |
|-------|------|-------------|-------------|
| LikeID | Integer | Unique identifier | Primary Key, Auto-increment |
| MaterialID | Integer | ID of the material | Foreign Key |
| UserID | Integer | ID of the user | Foreign Key |
| LikeDate | DateTime | When user liked material | Default: Current Time |

## ER Diagram

```
+----------------+         +-------------------+
|     User       |         |   StudyMaterial   |
+----------------+         +-------------------+
| PK UserID      |<------o<| PK MaterialID     |
| Email          |         | Title             |
| Name           |         | Description       |
| College        |         | Type              |
| Stream         |         | Subject           |
| JoinDate       |         | UploadDate        |
| Role           |         | FilePath          |
+----------------+         | YouTubeLink       |
        |                  | FK UploadedBy     |
        |                  | LikeCount         |
        |                  +-------------------+
        |                           |
        |                           |
        |                  +-------------------+
        |                  |   MaterialLikes   |
        |                  +-------------------+
        |                  | PK LikeID         |
        +----------------->| FK UserID         |
                           | FK MaterialID     |
                           | LikeDate          |
                           +-------------------+
        |
        |
        |                  +-------------------+
        |                  |    StudyGroup     |
        |                  +-------------------+
        +----------------->| PK GroupID        |
                           | GroupName         |
                           | Description       |
                           | IsPublic          |
                           | FK CreatedBy      |
                           | CreationDate      |
                           +-------------------+
                                    |
                                    |
                           +-------------------+
                           | GroupMembership   |
                           +-------------------+
                           | PK MembershipID   |
                           | FK GroupID        |
        +----------------->| FK UserID         |
                           | JoinDate          |
                           +-------------------+
```

## Data Design

### Database Selection

PostgreSQL has been selected as the database management system for the following reasons:
- Support for complex queries and relationships
- Excellent handling of concurrent operations
- Strong data integrity features
- Good scalability characteristics
- Open-source with strong community support

### Data Storage

1. **User Data**: Stored in the PostgreSQL database with sensitive fields encrypted.
2. **Study Materials**: 
   - Metadata stored in PostgreSQL.
   - Actual files stored in cloud storage (AWS S3/Firebase Storage).
   - URLs to files stored in the database.
3. **Study Groups**: Stored in PostgreSQL with references to members and shared materials.
4. **Likes and Interactions**: Stored in PostgreSQL for analytics and recommendation generation.

### Data Access

1. **ORM Layer**: Sequelize/Prisma will be used as an ORM to abstract database operations.
2. **API Layer**: RESTful APIs will serve as the interface between frontend and database.
3. **Caching**: Redis will be used to cache frequently accessed data to improve performance.
4. **Search Indexing**: Meilisearch/Algolia will be used to index study materials for fast search.

## Component Level Diagram

```
+------------------+        +------------------+
|  Authentication  |<------>|  User Profile    |
|  Component       |        |  Component       |
+------------------+        +------------------+
        |                            |
        v                            v
+------------------+        +------------------+
|  Study Material  |<------>|  Study Group     |
|  Component       |        |  Component       |
+------------------+        +------------------+
        |                            |
        v                            v
+------------------+        +------------------+
|  Search &        |<------>|  Content         |
|  Discovery       |        |  Moderation      |
+------------------+        +------------------+
        |                            |
        v                            v
+------------------+        +------------------+
|  File Storage    |<------>|  Analytics       |
|  Service         |        |  Service         |
+------------------+        +------------------+
```

## Project Scheduling

### Phase 1: Initial Development (2 months)
- Week 1-2: Requirements gathering and analysis
- Week 3-4: Database design and setup
- Week 5-6: Authentication system implementation
- Week 7-8: Basic study material upload/view functionality

### Phase 2: Core Features Development (3 months)
- Week 9-10: Study group creation and management
- Week 11-12: Search and filtering functionality
- Week 13-14: Content moderation tools
- Week 15-16: User interface refinement
- Week 17-20: Testing and bug fixing

### Phase 3: Beta Release and Refinement (2 months)
- Week 21-22: Limited beta release
- Week 23-24: Gather and analyze user feedback
- Week 25-28: Implement improvements based on feedback

### Phase 4: Full Launch and Expansion (3 months)
- Week 29-32: Full platform launch
- Week 33-36: Monitoring and performance optimization
- Week 37-40: Development of additional features

## Timeline Chart

```
Month 1   Month 2   Month 3   Month 4   Month 5   Month 6   Month 7   Month 8   Month 9   Month 10
|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|
   [Requirements & Analysis]
           [Database Design]
                     [Authentication]
                               [Basic Functionality]
                                         [Study Groups]
                                                   [Search]
                                                             [Moderation]
                                                                       [UI Refinement]
                                                                                 [Testing]
                                                                                           [Beta Release]
                                                                                                     [Feedback]
                                                                                                               [Improvements]
                                                                                                                         [Full Launch]
                                                                                                                                   [Monitoring]
                                                                                                                                             [Expansion]
```

## Function Point Metrics

### Function Point Analysis

| Component Type | Low Complexity | Average Complexity | High Complexity | Total |
|----------------|----------------|-------------------|-----------------|-------|
| External Inputs | 4 x 3 = 12 | 5 x 4 = 20 | 3 x 6 = 18 | 50 |
| External Outputs | 3 x 4 = 12 | 4 x 5 = 20 | 2 x 7 = 14 | 46 |
| External Inquiries | 5 x 3 = 15 | 4 x 4 = 16 | 2 x 6 = 12 | 43 |
| Internal Logical Files | 2 x 7 = 14 | 4 x 10 = 40 | 1 x 15 = 15 | 69 |
| External Interface Files | 1 x 5 = 5 | 2 x 7 = 14 | 1 x 10 = 10 | 29 |

**Total Function Points (Unadjusted)**: 237

### Complexity Adjustment Factors

| Factor | Description | Weight (0-5) |
|--------|-------------|--------------|
| Data Communications | Multiple platforms and devices | 4 |
| Distributed Functions | Distributed data processing | 3 |
| Performance | Response time critical for searches | 4 |
| Heavily Used Configuration | High usage expected | 3 |
| Transaction Rate | Moderate | 3 |
| Online Data Entry | High online entry | 4 |
| End-User Efficiency | Key consideration | 5 |
| Online Update | Real-time updates needed | 4 |
| Complex Processing | Content moderation is complex | 3 |
| Reusability | Components should be reusable | 4 |
| Installation Ease | Easy installation required | 2 |
| Operational Ease | Must be easy to operate | 4 |
| Multiple Sites | Multiple colleges | 3 |
| Facilitate Change | Easy maintenance | 4 |

**Total Adjustment Factor**: 0.65 + (0.01 × 50) = 1.15

**Adjusted Function Points**: 237 × 1.15 = 273

## COCOMO Model

Using the Intermediate COCOMO model for a semi-detached project:

### Inputs
- Adjusted Function Points: 273
- Conversion to SLOC (JavaScript): 273 × 53 = 14,469 SLOC
- KSLOC: 14.469

### Constants for Semi-detached Mode
- a = 3.0
- b = 1.12
- c = 2.5
- d = 0.35

### Effort Multipliers
- Product complexity (CPLX): 1.15 (High)
- Required reusability (RUSE): 1.08 (High)
- Platform difficulty (PDIF): 1.00 (Nominal)
- Personnel capability (PERS): 0.92 (High)
- Experience (PREX): 1.00 (Nominal)
- Facilities (FCIL): 0.95 (Good)
- Schedule (SCED): 1.00 (Nominal)

**Effort Adjustment Factor (EAF)**: 1.15 × 1.08 × 1.00 × 0.92 × 1.00 × 0.95 × 1.00 = 1.08

### Calculations
- **Effort**: 3.0 × (14.469)^1.12 × 1.08 = 58.2 person-months
- **Duration**: 2.5 × (58.2)^0.35 = 10.6 months
- **Average Staff Required**: 58.2 / 10.6 = 5.5 ≈ 6 persons

## Sample Screenshots

### Login Screen
```
+-----------------------------------------------------+
|                                                     |
|                  E-Learning Platform                |
|                                                     |
|   +-------------------------------------------+     |
|   |                                           |     |
|   |             [Google Sign-In]              |     |
|   |                                           |     |
|   +-------------------------------------------+     |
|                                                     |
|                                                     |
|   Welcome to the platform for Indian college        |
|   students to access study materials and            |
|   collaborate with peers.                           |
|                                                     |
+-----------------------------------------------------+
```

### Home Dashboard
```
+-----------------------------------------------------+
| E-Learning Platform          [Search] [Profile]     |
+-----------------------------------------------------+
|                                                     |
| Welcome, [User Name]                                |
|                                                     |
| +--------------+  +----------------+  +------------+|
| | Study        |  | My Study       |  | Recent     ||
| | Materials    |  | Groups         |  | Activity   ||
| |              |  |                |  |            ||
| | PYQs         |  | Group 1        |  | User A     ||
| | Notes        |  | Group 2        |  | uploaded   ||
| | Videos       |  |                |  | Physics    ||
| |              |  | + Create New   |  | notes      ||
| +--------------+  +----------------+  +------------+|
|                                                     |
| Recommended for [Your Stream]:                      |
|                                                     |
| +-----------------------------------------------+   |
| | [Material 1] | [Material 2] | [Material 3]    |   |
| +-----------------------------------------------+   |
|                                                     |
+-----------------------------------------------------+
```

### Study Material Upload
```
+-----------------------------------------------------+
| E-Learning Platform          [Search] [Profile]     |
+-----------------------------------------------------+
|                                                     |
| Upload Study Material                               |
|                                                     |
| Title: [________________________]                   |
|                                                     |
| Description:                                        |
| [                                                 ] |
| [                                                 ] |
|                                                     |
| Type:   () PYQ  () Notes  () YouTube Video         |
|                                                     |
| Subject: [_______________]                          |
|                                                     |
| File Upload: [Browse...] or                         |
| YouTube URL: [________________________]             |
|                                                     |
| [Cancel]           [Upload Material]                |
|                                                     |
+-----------------------------------------------------+
```

## Risk Analysis

### Risk Assessment Matrix

| Risk | Probability (1-5) | Impact (1-5) | Risk Score | Mitigation Strategy |
|------|------------------|-------------|------------|---------------------|
| Data security breach | 3 | 5 | 15 | Implement strong encryption, regular security audits, and compliance with data protection standards |
| Poor user adoption | 4 | 4 | 16 | Conduct thorough user research, implement intuitive design, and develop a strong onboarding process |
| Server overload during exam seasons | 4 | 3 | 12 | Implement auto-scaling, CDN, and optimize database queries |
| Copyright issues with uploaded content | 3 | 4 | 12 | Develop clear policies, implement reporting system, and content moderation |
| Inadequate content quality | 3 | 4 | 12 | Implement rating system, moderation, and quality guidelines |
| Technical issues with file uploads | 2 | 3 | 6 | Thorough testing, clear file size limits, and helpful error messages |
| Integration issues with third-party services | 2 | 3 | 6 | Develop fallback mechanisms and thoroughly test integrations |
| Feature scope creep | 3 | 3 | 9 | Implement clear project management methodologies and prioritize features |

### Risk Response Planning

1. **High-Risk Items (Score > 12)**:
   - Data security breach: Engage security experts, implement encryption, and conduct regular audits.
   - Poor user adoption: Create an MVP first, gather feedback, and iterate based on user needs.

2. **Medium-Risk Items (Score 7-12)**:
   - Server overload: Design for scalability from the start, implement caching.
   - Copyright issues: Develop clear policies and automated detection systems.
   - Inadequate content quality: Implement peer review and rating systems.

3. **Low-Risk Items (Score < 7)**:
   - Technical issues with file uploads: Thorough testing and clear user instructions.
   - Integration issues: Careful selection of technologies with good support.

## Testing

### Testing Strategy

The e-learning platform will undergo comprehensive testing across different levels:

1. **Unit Testing**:
   - Test individual components and functions
   - Framework: Jest for JavaScript
   - Coverage target: Minimum 80% code coverage

2. **Integration Testing**:
   - Test interactions between components
   - API endpoint testing
   - Database integration testing
   - File upload integration testing

3. **System Testing**:
   - End-to-end testing of complete user flows
   - Performance testing under various loads
   - Cross-browser and cross-device testing
   - Framework: Cypress for end-to-end testing

4. **User Acceptance Testing**:
   - Beta testing with actual college students
   - Gathering feedback through surveys and interviews
   - Usability testing to evaluate interface and experience

### Test Cases

| Test ID | Module | Description | Test Steps | Expected Result |
|---------|--------|-------------|------------|-----------------|
| TC001 | Authentication | Verify Google Sign-In | 1. Click on Google Sign-In<br>2. Authorize the application | User should be logged in and redirected to dashboard |
| TC002 | Study Materials | Upload file | 1. Navigate to upload page<br>2. Fill details<br>3. Upload file<br>4. Submit | File should be uploaded and appear in the system |
| TC003 | Study Groups | Create group | 1. Navigate to groups<br>2. Click create new<br>3. Fill details<br>4. Submit | Group should be created and user added as creator |
| TC004 | Search | Search by subject | 1. Enter subject name in search<br>2. Apply filters<br>3. Submit search | Relevant materials should be displayed |
| TC005 | Content Moderation | Flag inappropriate content | 1. View content<br>2. Click report button<br>3. Select reason<br>4. Submit | Content should be flagged for review |

## Conclusion

The E-Learning Platform for Indian college students addresses a critical need in the educational ecosystem by providing a centralized hub for study materials and collaborative learning. The platform's focus on PYQs, notes, and curated YouTube playlists, combined with study group functionality, creates a comprehensive solution for students seeking to improve their academic performance.

The development approach using the Incremental Model allows for gradual implementation of features, ensuring that each component meets user needs before moving to the next phase. The technical architecture, based on Next.js, Express.js, PostgreSQL, and cloud storage, provides a robust foundation for scalability and performance.

Key success factors for this platform include:

1. **User-Centric Design**: The minimal, mobile-friendly interface focuses on simplicity and ease of use.
2. **Content Quality**: Through moderation tools and user ratings, the platform will maintain high-quality study materials.
3. **Collaborative Features**: Study groups enable peer learning and knowledge sharing.
4. **Personalization**: Academic stream-based recommendations enhance relevance.

As the platform grows, it has the potential to expand beyond college students to serve other educational segments, including competitive exam aspirants and school students. With careful attention to security, performance, and user feedback, the E-Learning Platform will become an essential tool in the Indian educational landscape, helping students access quality resources and succeed in their academic pursuits.


# Figure List

| **Figure No.** | **Name**                                 |
|----------------|-------------------------------------------|
| 1.             | Context Level DFD                         |
| 2.             | Level-1 DFD                               |
| 3.             | Level-2: User Registration                |
| 4.             | Level-2: User Login                       |
| 5.             | Level-2: View Study Materials             |
| 6.             | Level-2: Upload Study Materials           |
| 7.             | Level-2: Join/Create Study Group          |
| 8.             | Entity-Relationship (ER) Diagram          |
| 9.             | Data Flow of Study Material Management    |
| 10.            | System Use Case Diagram (Student)         |
| 11.            | System Use Case Diagram (Admin)           |
| 12.            | Home Page                                 |
| 13.            | Login and Registration Page               |
| 14.            | Student Dashboard                         |
| 15.            | View Previous Year Papers Page            |
| 16.            | View Notes and Playlists Page             |
| 17.            | Create or Join Study Group Page           |
| 18.            | Group Chat and Resource Sharing Page      |
| 19.            | Upload Study Material Page                |
| 20.            | Search and Filter Page                    |
| 21.            | Admin Login Page                          |
| 22.            | Admin Dashboard                           |
| 23.            | Admin View Reports and Flags              |
| 24.            | Admin Manage Users and Materials          |

